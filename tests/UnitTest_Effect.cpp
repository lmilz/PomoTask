#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "Effect.h"

// Mock implementation for testing terminal-specific methods
class MockEffect : public Effect {
 public:
  MockEffect(int rows, int cols, int color) : Effect(rows, cols, color) {}
  void run() override {}

  // Expose protected methods for testing
  void testSetCursorPosition(int row, int col) { setCursorPosition(row, col); }

  void testSetTextColor() { setTextColor(); }

  void testClearScreen() { clearScreen(); }
};

// Test group for the BaseEffect class
TEST_GROUP(EffectTests) {
  MockEffect* effect;

  void setup() { effect = new MockEffect(10, 20, 30); }

  void teardown() { delete effect; }
};

TEST(EffectTests, ConstructorInitializesValues) {
  CHECK(10 == effect->getRows());
  CHECK(20 == effect->getCols());
  CHECK(30 == effect->getColor());
}

TEST(EffectTests, Setter_Getter_Rows) {
  effect->setRows(40);
  CHECK(40 == effect->getRows());
}

TEST(EffectTests, Setter_Getter_Cols) {
  effect->setCols(50);
  CHECK(50 == effect->getCols());
}

TEST(EffectTests, Setter_Getter_Color) {
  effect->setColor(60);
  CHECK(60 == effect->getColor());
}