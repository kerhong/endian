//  buffer_test.cpp  -------------------------------------------------------------------//

//  Copyright Beman Dawes 2014

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See library home page at http://www.boost.org/libs/endian

//--------------------------------------------------------------------------------------//

#include <boost/endian/detail/disable_warnings.hpp>

//#define BOOST_ENDIAN_LOG
#include <boost/endian/buffers.hpp>
#include <boost/detail/lightweight_main.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <iostream>
#include <sstream>

using namespace boost::endian;
using std::cout;
using std::endl;

namespace
{

  //  check_size  ------------------------------------------------------------//

  void check_size()
  {

    BOOST_TEST_EQ(sizeof(big_float32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(big_float64_buf_t), 8u);
    BOOST_TEST_EQ(sizeof(little_float32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(little_float64_buf_t), 8u);
    BOOST_TEST_EQ(sizeof(native_float32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(native_float64_buf_t), 8u);

    BOOST_TEST_EQ(sizeof(big_float32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(big_float64_buf_ut), 8u);
    BOOST_TEST_EQ(sizeof(little_float32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(little_float64_buf_ut), 8u);
    BOOST_TEST_EQ(sizeof(native_float32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(native_float64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(big_int8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(big_int16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(big_int24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(big_int32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(big_int40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(big_int48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(big_int56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(big_int64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(big_uint8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(big_uint16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(big_uint24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(big_uint32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(big_uint40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(big_uint48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(big_uint56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(big_uint64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(little_int8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(little_int16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(little_int24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(little_int32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(little_int40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(little_int48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(little_int56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(little_int64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(little_uint8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(little_uint16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(little_uint24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(little_uint32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(little_uint40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(little_uint48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(little_uint56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(little_uint64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(native_int8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(native_int16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(native_int24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(native_int32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(native_int40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(native_int48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(native_int56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(native_int64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(native_uint8_buf_ut), 1u);
    BOOST_TEST_EQ(sizeof(native_uint16_buf_ut), 2u);
    BOOST_TEST_EQ(sizeof(native_uint24_buf_ut), 3u);
    BOOST_TEST_EQ(sizeof(native_uint32_buf_ut), 4u);
    BOOST_TEST_EQ(sizeof(native_uint40_buf_ut), 5u);
    BOOST_TEST_EQ(sizeof(native_uint48_buf_ut), 6u);
    BOOST_TEST_EQ(sizeof(native_uint56_buf_ut), 7u);
    BOOST_TEST_EQ(sizeof(native_uint64_buf_ut), 8u);

    BOOST_TEST_EQ(sizeof(big_int16_buf_t), 2u);
    BOOST_TEST_EQ(sizeof(big_int32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(big_int64_buf_t), 8u);

    BOOST_TEST_EQ(sizeof(big_uint16_buf_t), 2u);
    BOOST_TEST_EQ(sizeof(big_uint32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(big_uint64_buf_t), 8u);

    BOOST_TEST_EQ(sizeof(little_int16_buf_t), 2u);
    BOOST_TEST_EQ(sizeof(little_int32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(little_int64_buf_t), 8u);

    BOOST_TEST_EQ(sizeof(little_uint16_buf_t), 2u);
    BOOST_TEST_EQ(sizeof(little_uint32_buf_t), 4u);
    BOOST_TEST_EQ(sizeof(little_uint64_buf_t), 8u);
  } // check_size

  //  test_inserter_and_extractor  -----------------------------------------------------//

  void test_inserter_and_extractor()
  {
    std::cout << "test inserter and extractor..." << std::endl;

    big_uint64_buf_ut bu64(0x010203040506070ULL);
    little_uint64_buf_ut lu64(0x010203040506070ULL);

    uint64_t x;

    std::stringstream ss;

    ss << bu64;
    ss >> x;
    BOOST_TEST_EQ(x, 0x010203040506070ULL);

    ss.clear();
    ss << lu64;
    ss >> x;
    BOOST_TEST_EQ(x, 0x010203040506070ULL);

    ss.clear();
    ss << 0x010203040506070ULL;
    big_uint64_buf_ut bu64z(0);
    ss >> bu64z;
    BOOST_TEST_EQ(bu64z.value(), bu64.value());

    ss.clear();
    ss << 0x010203040506070ULL;
    little_uint64_buf_ut lu64z(0);
    ss >> lu64z;
    BOOST_TEST_EQ(lu64z.value(), lu64.value());

    std::cout << "test inserter and extractor complete" << std::endl;

  }

}  // unnamed namespace

//--------------------------------------------------------------------------------------//

int cpp_main(int, char *[])
{
  cout << "byte swap intrinsics: " BOOST_ENDIAN_INTRINSIC_MSG << endl;

  cout << "  construct big endian aligned" << endl;
  big_int32_buf_t x(1122334455);

  cout << "  assign to buffer from built-in integer" << endl;
  x = 1234567890;

  cout << "  operator==(buffer.value(), built-in)" << endl;
  bool b1(x.value() == 1234567890);
  BOOST_TEST(b1);

  cout << "  construct little endian unaligned" << endl;
  little_int32_buf_ut x2(1122334455);

  cout << "  assign to buffer from built-in integer" << endl;
  x2 = 1234567890;

  cout << "  operator==(buffer.value(), built-in)" << endl;
  bool b2(x2.value() == 1234567890);
  BOOST_TEST(b2);

  check_size();
  test_inserter_and_extractor();

  cout << "  done" << endl;

  return ::boost::report_errors();
}

#include <boost/endian/detail/disable_warnings_pop.hpp>
