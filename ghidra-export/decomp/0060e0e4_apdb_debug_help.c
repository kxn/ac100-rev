// func apdb_debug_help @ 0060e0e4 size=1

void apdb_debug_help(void)

{
  puts("apdb debug commands:");
  puts("apdb_debug_help() -- help menu");
  puts("apdb_debug_print_ap_cnt() -- show number of ap models");
  puts("apdb_debug_print_ap_all() -- show all ap models\' parameters");
  puts("apdb_debug_print_json() -- show apdb json data");
  puts("apdb_debug_stat_dump() -- show malloc and free times");
  puts("apdb_debug_print_json_in_mem() -- show apdb json for mem");
  puts("apdb_debug_print_all_ap_verbose() -- show apdb verbose");
  puts(
      "apdb_debug_print_specific_ap_verbose(int model_id) -- show specific ap model_id apdb verbose"
      );
  puts("apdb_debug_print_unsupport_json() -- show unsupport ap list in json object");
  puts("apdb_debug_print_unsupport_hash() -- show unsupport ap list in hash object");
  puts("apdb_phy_info_dump() -- show apdb phy info");
  puts("apdb_region_list_dump() -- show apdb region list");
  puts("apdb_rrst_dump() -- show apdb radio role search table");
  puts("apdb_debug_switch=1/0 -- enable/disable debug info");
  puts("apdb_warning_switch=1/0 -- enable/disable warning info");
  (*(code *)PTR_puts_00758f90)("apdb_err_switch=1/0 -- enable/disable error info");
  return;
}

