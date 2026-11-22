// func balance_db_config_dump @ 0045e554 size=32

void balance_db_config_dump(void)

{
  if (balance_com != 0) {
    balance_config_dump(balance_com + 8);
    return;
  }
  return;
}

