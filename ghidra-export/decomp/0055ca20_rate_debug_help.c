// func rate_debug_help @ 0055ca20 size=1

void rate_debug_help(void)

{
  puts("Interface Helper:");
  puts("\trate_db_dump():\tdump radio rate configuration.");
  puts("Switch Helper:");
  puts("\trate_err_switch:\tlevel[ERROR]\'s switch.");
  (*(code *)PTR_puts_00758f90)("\trate_debug_switch:\tlevel[DEBUG]\'s switch.");
  return;
}

