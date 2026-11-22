// func _wportal_db_username_hash_aut_foreach_cb_func @ 0042b418 size=264

void _wportal_db_username_hash_aut_foreach_cb_func(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    printf(" Hash node username: %s\n",param_1);
    for (iVar1 = FUN_004081b0(param_1 + 0x68); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      if (iVar1 == 0x11c) {
        puts("Get list entry error");
      }
      else {
        printf("   autEntry: vlan %d, wserid: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, auth_type: %d, IP: %s, expire: %d\n"
               ,*(undefined4 *)(iVar1 + -0x108),*(undefined4 *)(iVar1 + -0x108),
               (uint)*(byte *)(iVar1 + -0x110),(uint)*(byte *)(iVar1 + -0x10f),
               (uint)*(byte *)(iVar1 + -0x10e),(uint)*(byte *)(iVar1 + -0x10d),
               (uint)*(byte *)(iVar1 + -0x10c),(uint)*(byte *)(iVar1 + -0x10b),
               (uint)*(byte *)(iVar1 + -0x9c),iVar1 + -0xc4,*(undefined4 *)(iVar1 + -0xe0));
      }
    }
    putchar(10);
    return;
  }
  puts(" Get hash node error");
  return;
}

