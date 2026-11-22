// func band_navigation_debug_help @ 0055f918 size=1

void band_navigation_debug_help(void)

{
  puts("Interface Helper:");
  puts("\tband_navigation_db_dump():\tdump band navigation configuration.");
  puts("Switch Helper:");
  puts("\tband_navigation_err_switch:\tlevel[ERROR]\'s switch.");
  (*(code *)PTR_puts_00758f90)("\tband_navigation_debug_switch:\tlevel[DEBUG]\'s switch.");
  return;
}

