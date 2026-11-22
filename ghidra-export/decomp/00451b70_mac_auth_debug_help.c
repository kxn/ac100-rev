// func mac_auth_debug_help @ 00451b70 size=1

void mac_auth_debug_help(void)

{
  puts("Interface Helper:");
  puts("\tmac_auth_print_profile():\tdump mac auth profile configuration.");
  puts("\tmac_auth_print_all_mac():\tdump all mac entry.");
  puts("\tmac_auth_print_all_group():\tdump all mac auth entry.");
  puts("\tmac_auth_print_all():\tmac_auth_print_all_mac()+mac_auth_print_all_group().");
  puts("\tmac_auth_print_mem_stat():\tdump total memery used by mac auth.");
  puts("Switch Helper:");
  puts("\tmacauth_err_switch:\tlevel[ERROR]\'s switch.");
  puts("\tmacauth_warning_switch:\tlevel[DEBUG]\'s switch.");
  (*(code *)PTR_puts_00758f90)("\tmacauth_debug_switch:\tlevel[DEBUG]\'s switch.");
  return;
}

