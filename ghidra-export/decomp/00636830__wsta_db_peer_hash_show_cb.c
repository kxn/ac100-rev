// func _wsta_db_peer_hash_show_cb @ 00636830 size=1

void _wsta_db_peer_hash_show_cb(byte *param_1)

{
  puts("*******************************************");
  printf("mld mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)param_1[6],(uint)param_1[7],
         (uint)param_1[8],(uint)param_1[9],(uint)param_1[10],(uint)param_1[0xb]);
  printf("\tpeer mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*param_1,(uint)param_1[1],
         (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  return;
}

