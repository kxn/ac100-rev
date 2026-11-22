// func print_passthrough_response_get_from_one_ap @ 0050cde0 size=96

undefined4 print_passthrough_response_get_from_one_ap(void)

{
  int iVar1;
  
  iVar1 = get_reponse_by_id_from_list();
  if (iVar1 != 0) {
    puts("\r");
    printf("\t\tid:%d len:%d data:%s\r\n",*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10)
           ,*(undefined4 *)(iVar1 + 0x18));
  }
  puts("\r");
  return 0;
}

