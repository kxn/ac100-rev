// func mac_auth_print_mac_entry @ 00457718 size=164

void mac_auth_print_mac_entry(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (macauth_debug_switch != 0)) {
    puts("#####################################################################");
    printf("id\t\t\t    = %d\n",*param_1);
    printf("name\t\t    = %s\n",param_1 + 1);
    printf("mac\t\t        = [%02X:%02X:%02X:%02X:%02X:%02X]\n",(uint)*(byte *)(param_1 + 0x28),
           (uint)*(byte *)((int)param_1 + 0xa1),(uint)*(byte *)((int)param_1 + 0xa2),
           (uint)*(byte *)((int)param_1 + 0xa3),(uint)*(byte *)(param_1 + 0x29),
           (uint)*(byte *)((int)param_1 + 0xa5));
    puts("\n#####################################################################");
    return;
  }
  return;
}

