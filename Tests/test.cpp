#include "pch.h"
#include "Task.h"
#include <iostream>
#include <fstream>
using namespace std;


TEST(TestTask, BadFileName) {
	string fileName = "test.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, -1);
}

TEST(TestTask, EmptyFile0Sentences) {
	string fileName = "test1.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 0);
}

TEST(TestTask, FileWithSpaces0Sentences) {
	string fileName = "test2.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 0);
}

TEST(TestTask, FileWithDelimiters0Sentences) {
	string fileName = "test3.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 0);
}

TEST(TestTask, FileWith1SentencesWithoutDelimiters) {
	string fileName = "test4.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 1);
}

TEST(TestTask, FileWith5Sentences) {
	string fileName = "test5.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 5);
}

TEST(TestTask, FileWith5SentencesWithATrailingDot) {
	string fileName = "test6.txt";
	int count = GetSentencesCount(fileName);
	EXPECT_EQ(count, 5);
}