// func arp_defend_debug_help @ 004772d8 size=1

void arp_defend_debug_help(void)

{
  puts("Interface Helper:");
  puts("\tarp_defend_print_profile():\tdump arp defend profile configuration.");
  puts("\tarp_defend_print_all_ap():\tdump all arp binding entry.");
  puts("\tarp_defend_print_all_arp():\tdump all arp entry.");
  puts("\tarp_defend_print_all():\tarp_defend_print_all_ap()+arp_defend_print_all_arp().");
  puts(
      "\tarp_defend_print_msgq():\tdump infomation of message queue,including max size,current size..."
      );
  puts("\tarp_defend_print_mem_stat():\tdump total memery used by arp defend.");
  puts("Switch Helper:");
  puts("\tarp_defend_err_switch:\tlevel[ERROR]\'s switch.");
  puts("\tarp_defend_warning_switch:\tlevel[WARNING]\'s switch.");
  (*(code *)PTR_puts_00758f90)("\tarp_defend_debug_switch:\tlevel[DEBUG]\'s switch.");
  return;
}

