// func apupd_debug_help @ 00648f0c size=124

void apupd_debug_help(void)

{
  puts("Interface Helper:");
  puts(
      "\tapupd_db_model_hash_dump()/apupd_db_model_list_dump():\tdump upgrade infomation of each model,including state,file size...."
      );
  puts(
      "\tapupd_db_update_model_list_dump():\tdump upgrade infomation of each upgrading model,including state,file size...."
      );
  puts("\tapupd_db_wtp_hash_dump():\tdump upgrade infomation of each wtp,including ip,mac,state...."
      );
  puts(
      "\tapupd_db_profile_dump():\tdump upgrade profile configuration,including max wtps,max upgrade models...."
      );
  puts("Switch Helper:");
  puts("\tg_apupd_error:\tlevel[ERROR]\'s switch.");
  puts("\tg_apupd_debug:\tlevel[DEBUG]\'s switch.");
  puts("\tg_apupd_pkt_switch:\tapupd control packet dump switch.");
  return;
}

