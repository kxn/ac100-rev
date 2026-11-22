// func balance_db_profile_dump @ 0045e4ec size=104

void balance_db_profile_dump(void)

{
  if (balance_com != (undefined4 *)0x0) {
    puts("balance profile:");
    printf("\tmax wtp number: %d \r\n",*balance_com);
    printf("\tmax station number: %d \r\n",balance_com[1]);
    return;
  }
  return;
}

