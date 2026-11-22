// func multi_link_debug_help @ 00664944 size=1

void multi_link_debug_help(void)

{
  puts("multi_link debug commands:");
  puts("multi_link_err_switch       -- error switch");
  puts("multi_link_warning_switch   -- warning switch");
  puts("multi_link_debug_switch     -- debug switch");
  (*(code *)PTR_puts_00758f90)("multi_link_debug_config_show()  -- show multi_link config info");
  return;
}

