// func _wportal_db_dm_sessid_rbtree_print @ 0042afec size=132

undefined4 _wportal_db_dm_sessid_rbtree_print(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    printf("   autEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, auth_type: %d, framed ip: %s, expire: %llu, sesssid: %llu\n"
           ,*(undefined4 *)(param_2 + 0x14),(uint)*(byte *)(param_2 + 0xc),
           (uint)*(byte *)(param_2 + 0xd),(uint)*(byte *)(param_2 + 0xe),
           (uint)*(byte *)(param_2 + 0xf),(uint)*(byte *)(param_2 + 0x10),
           (uint)*(byte *)(param_2 + 0x11),(uint)*(byte *)(param_2 + 0x80),param_2 + 0x58,0,
           *(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x160),
           *(undefined4 *)(param_2 + 0x164));
  }
  return 0;
}

