// func _stats_db_print_bssid_cb @ 00667e2c size=144

void _stats_db_print_bssid_cb(byte *param_1)

{
  if (param_1 != (byte *)0x0) {
    printf("bssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    printf("\tap id: %u \r\n",(uint)*(ushort *)(param_1 + 6));
    printf("\tradio id: %u \r\n",(uint)param_1[8]);
    printf("\twlan id: %u \r\n",(uint)param_1[9]);
    return;
  }
  return;
}

