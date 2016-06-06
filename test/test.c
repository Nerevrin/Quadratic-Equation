#include <stdlib.h>
#include "../thirdparty/ctest.h"
#include "../src/discr.h"
#include "../src/equat.h"

CTEST_DATA(test_data)
{
    int a;
    int b;
    int c;
    float real_d;
    float ex_d;
    float root[1];
    float ex_root[1];
    int real_flg;
    int ex_flg;
};

CTEST2(test_data, test_d1) 
{
    data->a = 1;
    data->b = 3;
    data->c = 2;
    
    data->ex_d= 1;
	data->real_d = discr(data->a, data->b, data->c);
	ASSERT_EQUAL(data->ex_d, data->real_d);
}

CTEST2(test_data, test_d2) 
{
    data->a = 1;
    data->b = 3;
    data->c = 3;
    
    data->ex_d = -1;
	data->real_d = discr(data->a, data->b, data->c);
	ASSERT_EQUAL(data->ex_d, data->real_d);
}

CTEST2(test_data, a_zero)
{
	data->a = 0;
	data->b = 4;
	data->c = 2;
	data->ex_flg = 1;
	
	data->real_flg = equat(data->a, data->b, data->c, data->root);
	
	ASSERT_EQUAL(data->ex_flg, data->real_flg);
}


