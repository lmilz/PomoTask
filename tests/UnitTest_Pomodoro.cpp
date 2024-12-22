#include "CppUTest/TestHarness.h"
#include "Pomodoro.h"

// Test group for the Pomodoro class
TEST_GROUP(PomodoroTests) {
  Pomodoro* pom;

  void setup() { pom = new Pomodoro(10, 20); }

  void teardown() { delete pom; }
};

TEST(PomodoroTests, ConstructorInitializesValues) { CHECK_EQUAL(pom->getFocusTime(), 600); }