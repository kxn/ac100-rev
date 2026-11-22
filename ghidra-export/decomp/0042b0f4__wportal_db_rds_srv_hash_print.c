// func _wportal_db_rds_srv_hash_print @ 0042b0f4 size=132

void _wportal_db_rds_srv_hash_print(int param_1)

{
  undefined1 auStack_50 [68];
  
  memset(auStack_50,0,0x40);
  printf("  Server index: %d, authport: %d, acctport: %d, Authtype: %d, Psk: %s, resend intvl: %d, resend cnt: %d, nasid: %s, nasip: %s, serverip: %s\n"
         ,*(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x10c),
         *(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0x11c),param_1,
         *(undefined4 *)(param_1 + 0x118),*(undefined4 *)(param_1 + 0x114),param_1 + 0x79,
         param_1 + 0xde,auStack_50);
  return;
}

