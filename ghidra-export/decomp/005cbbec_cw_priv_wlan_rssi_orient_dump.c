// func cw_priv_wlan_rssi_orient_dump @ 005cbbec size=196

undefined4 cw_priv_wlan_rssi_orient_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wlan rssi orient \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wlan rssi orient (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x%04x%02x%02x \r\n",*puVar1,(uint)*(ushort *)(puVar1 + 1),
         (uint)*(byte *)((int)puVar1 + 6),(uint)*(byte *)((int)puVar1 + 7));
  printf("\t\t\t\treject_limit: %d \r\n ",*puVar1);
  printf("\t\t\t\tradio_id: %u \r\n ",(uint)*(ushort *)(puVar1 + 1));
  printf("\t\t\t\treject_enable: %u \r\n ",(uint)*(byte *)((int)puVar1 + 6));
  printf("\t\t\t\treject_diff: %u \r\n ",(uint)*(byte *)((int)puVar1 + 7));
  return 0;
}

