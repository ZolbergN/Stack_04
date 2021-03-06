#include "catch.hpp"
#include <Stack.hpp>

TEST_CASE("Check functions", "[stack]") {
  SECTION("Check INIT")
  {
    Stack<int> st;
    REQUIRE(st.count() == 0);
  }
  SECTION("Check POP")
   {
    Stack<int> st;
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    REQUIRE(st.count() == 0);
  }
  SECTION("Check EMPTY")
  {
    Stack<int> st;
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    REQUIRE(st.count() == 0);
  }
  SECTION("Check PUSH")
  {
    Stack<int> st;
    st.push(3);
    st.push(4);
    REQUIRE(st.count() == 2);
  }
}
