#pragma once
#include "token.h"
#include "tag.h"
#include "tool.h"
#include "num.h"
#include "real.h"
#include "word.h"
#include <map>
#include <cctype>
#include <iostream>

class Lexer
{

  public:
	Lexer() : words{}, line{}
	{

		reserve(Word("if", Tag::IF));
		reserve(Word("else", Tag::ELSE));
		reserve(Word("while", Tag::WHILE));
		reserve(Word("do", Tag::DO));
		reserve(Word("break", Tag::BREAK));
		reserve(Word::fac(Tag::TURE));
		reserve(Word::fac(Tag::FALSE));
	}

	void reserve(Word w) { words.insert({w.toString(), w}); }

  public:
	Token scan()
	{

		for (;; readch())
		{

			if (peek == ' ' || peek == '\t')
				continue;
			else if (peek == '\n')
				line++;
			else
				break;
		}
		switch (peek)
		{

		case '$':
			if (readch('&'))
				return Word::fac(Tag::AND);
			else
				return Token(Tag::BA);
		case '|':
			if (readch('|'))
				return Word::fac(Tag::OR);
			else
				return Token(Tag::NB);
		case '=':
			if (readch('='))
				return Word::fac(Tag::EQ);
			else
				return Token(Tag::AS);
		case '!':
			if (readch('='))
				return Word::fac(Tag::NE);
			else
				return Token(Tag::IB);
		case '<':
			if (readch('='))
				return Word::fac(Tag::LE);
			else
				return Token(Tag::LB);
		case '>':
			if (readch('='))
				return Word::fac(Tag::GE);
			else
				return Token(Tag::BA);
		default:
			return Word::fac(Tag::NUll_T);
			break;
		}

		if (std::isdigit(peek))
		{

			int v = 0;

			do
			{
				v = 10 * v + std::stoi(std::string(1, peek), nullptr);
				readch();
			} while (std::isdigit(peek));

			if (peek != '.')
				return Num(v);
			float x = v;
			float d = 10;

			while (true)
			{

				readch();
				if (!std::isdigit(peek))
					break;
				x = x + std::stoi(std::string(1, peek)) / d;
				d = d * 10;
			}
			return Real(x);
		}

		if (isLetter(peek))
		{
			std::string s;

			do
			{

				s.append(1, peek);
				readch();

			} while (isLetter(peek));

			auto ite = words.find(s);

			if (ite != words.end())
			{

				return Word(ite->second);
			}

			Word w = Word(s, Tag::ID);

			words.insert({s, w});

			return w;
		}

		Token tok(static_cast<Tag>(static_cast<int>(peek)));
		peek = ' ';
		return tok;
	}

  private:
	void readch() inline { std::cin >> peek; }

	bool readch(char c)
	{
		readch();
		if (peek != c)
			return false;
		peek = ' ';
		return true;
	}

  private:
	std::map<std::string, Word> words;

	int line;

	char peek{};
};