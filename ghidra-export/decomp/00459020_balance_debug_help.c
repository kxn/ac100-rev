// func balance_debug_help @ 00459020 size=1

void balance_debug_help(void)

{
  puts("Interface Helper:");
  puts("balance_db_config_dump():\tdump balance configuration.");
  puts("balance_db_profile_dump():\tdump balance profile configuration.");
  puts("balance_db_com_dump():\tbalance_db_config_dump()+balance_db_profile_dump().");
  puts(
      "balance_db_wtp_array_dump()/balance_db_wtp_hash_dump:\tdump infomation of each wtp,including mac,station num..."
      );
  puts("balance_db_dis_sta_hash_dump():\tdump discovered wtp list of each station.");
  puts("Switch Helper:");
  puts("g_balance_error:\tlevel[ERROR]\'s switch.");
  puts("g_balance_warning:\tlevel[WARNING]\'s switch.");
  (*(code *)PTR_puts_00758f90)("g_balance_debug:\tlevel[DEBUG]\'s switch.");
  return;
}

