// func arp_defend_print_arp_entry @ 0047ecf0 size=236

void arp_defend_print_arp_entry(undefined4 *param_1)

{
  undefined1 auStack_90 [132];
  
  memset(auStack_90,0,0x80);
  if ((param_1 != (undefined4 *)0x0) && (arp_defend_debug_switch != 0)) {
    puts("#####################################################################");
    printf("arp_name\t\t= %s\n",(int)param_1 + 0x1e);
    printf("arp_id\t\t\t= %d\n",*param_1);
    FUN_00408190(param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],auStack_90,0x80,"---");
    printf("arp_ip\t\t    = %s\n",auStack_90);
    arp_defend_mac2str(param_1 + 6,auStack_90,0x80);
    printf("mac\t\t        = %s\n",auStack_90);
    puts("\n#####################################################################");
  }
  return;
}

