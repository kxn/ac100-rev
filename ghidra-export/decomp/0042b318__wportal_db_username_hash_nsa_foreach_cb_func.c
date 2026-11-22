// func _wportal_db_username_hash_nsa_foreach_cb_func @ 0042b318 size=256

void _wportal_db_username_hash_nsa_foreach_cb_func(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    printf(" Hash node username: %s\n",param_1);
    for (iVar1 = FUN_004081b0(param_1 + 0x68); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      if (iVar1 == 0x11c) {
        puts("Get list entry error");
      }
      else {
        printf("   nsaEntry: vlan %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, auth_type: %d, username: %s, passwd: %s\n"
               ,*(undefined4 *)(iVar1 + 0xc),(uint)*(byte *)(iVar1 + -0xa8),
               (uint)*(byte *)(iVar1 + -0xa7),(uint)*(byte *)(iVar1 + -0xa6),
               (uint)*(byte *)(iVar1 + -0xa5),(uint)*(byte *)(iVar1 + -0xa4),
               (uint)*(byte *)(iVar1 + -0xa3),*(undefined4 *)(iVar1 + 0x2c),iVar1 + -0xa2,
               iVar1 + -0x110);
      }
    }
    putchar(10);
    return;
  }
  puts(" Get hash node error");
  return;
}

