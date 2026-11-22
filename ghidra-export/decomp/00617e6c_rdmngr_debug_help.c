// func rdmngr_debug_help @ 00617e6c size=1

void rdmngr_debug_help(void)

{
  puts("Interface Helper:");
  puts("\trdmngr_print_profile():\tdump rdmngr profile configuration.");
  puts("\trdmngr_db_print_all():\tdump all rdmngr entry.");
  puts("\trdmngr_print_msgq():\tdump infomation of message queue,including max size,current size..."
      );
  puts("\trdmngr_print_mem_stat():\tdump total memery used by rdmngr.");
  puts("Switch Helper:");
  puts("\trdmngr_err_switch:\tlevel[ERROR]\'s switch.");
  puts("\trdmngr_warning_switch:\tlevel[WARNING]\'s switch.");
  (*(code *)PTR_puts_00758f90)("\trdmngr_debug_switch:\tlevel[DEBUG]\'s switch.");
  return;
}

