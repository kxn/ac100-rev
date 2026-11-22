// func _wportal_db_rds_srv_traverse_print @ 0042b200 size=184

undefined4 _wportal_db_rds_srv_traverse_print(undefined4 param_1,int param_2)

{
  undefined1 auStack_48 [64];
  
  memset(auStack_48,0,0x40);
  FUN_00408190(*(undefined4 *)(param_2 + 0x120),*(undefined4 *)(param_2 + 0x124),
               *(undefined4 *)(param_2 + 0x128),*(undefined4 *)(param_2 + 300),
               *(undefined4 *)(param_2 + 0x130),auStack_48,0x40,"---");
  printf("  Server index: %d, authport: %d, acctport: %d, Authtype: %d, Psk: %s, resend intvl: %d, resend cnt: %d, nasid: %s, nasip: %s serverip: %s\n"
         ,*(undefined4 *)(param_2 + 0x108),*(undefined4 *)(param_2 + 0x10c),
         *(undefined4 *)(param_2 + 0x110),*(undefined4 *)(param_2 + 0x11c),param_2,
         *(undefined4 *)(param_2 + 0x118),*(undefined4 *)(param_2 + 0x114),param_2 + 0x79,
         param_2 + 0xde,auStack_48);
  return 1;
}

