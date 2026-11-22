// func arp_defend_print_msgq @ 0047f09c size=88

void arp_defend_print_msgq(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_00408580(g_arp_defend_msgq);
  uVar2 = FUN_00408020(g_arp_defend_msgq);
  uVar3 = arp_defend_get_msgq_len();
  printf("maxMsgNum:%d, maxMsgSize:%d, curMsgNum:%d",uVar1,uVar2,uVar3);
  return;
}

