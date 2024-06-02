#include "../TTable/TArrayHashTable.h"
#include "gtest.h"
#include "string"
#include<random>
#include<ctime>
TEST(TArrayHashTable, can_create_Table)
{
    ASSERT_NO_THROW(TArrayHashTable table(10,4));
}


TEST(TArrayHashTable, can_insert)
{
    TArrayHashTable table(10,5);
    string str = "aaa";
    TRecord a;
    a.key = 1;
    a.val = str;
    ASSERT_NO_THROW(table.InsRec(a));
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());
}

TEST(TArrayHashTable, cant_insert_new_Record_in_Full_ArrayHashTable)
{
    mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distrib(1, 1000);
    TArrayHashTable t(10,5);
    TRecord rec;
    while (!t.Full())
    {
        int rand = distrib(gen);
        rec.key = rand;
        rec.val = to_string(rand) + "**";
        t.InsRec(rec);
    }
    ASSERT_ANY_THROW(t.InsRec(rec));

}
TEST(TArrayHashTable, can_delete)
{
    TArrayHashTable tab(10, 3);
    TRecord rec;
    rec.key = 2;
    rec.val = "fs";
    tab.InsRec(rec);
    tab.DelRec(2);
    EXPECT_EQ(tab.getRecord().key, -2);
}