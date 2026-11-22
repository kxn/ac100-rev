// func print_standby_ap_list_node @ 005338c8 size=156

void print_standby_ap_list_node(byte *param_1)

{
  if (param_1 != (byte *)0x0) {
    printf("\tap id: %d \n",(uint)*(ushort *)(param_1 + 6));
    printf("\tmac: %02X-%02X-%02X-%02X-%02X-%02X \n",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    FUN_00407e70();
    printf("\ttime: %lld \n");
    return;
  }
  return;
}

