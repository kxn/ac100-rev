// func balance_db_com_dump @ 0045e574 size=64

void balance_db_com_dump(void)

{
  if (balance_com != 0) {
    puts("balance com: ");
    balance_db_profile_dump();
    balance_db_config_dump();
    return;
  }
  return;
}

