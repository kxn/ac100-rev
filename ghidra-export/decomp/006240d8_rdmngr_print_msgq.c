// func rdmngr_print_msgq @ 006240d8 size=1

void rdmngr_print_msgq(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_00408580(g_rdmngr_msgq);
  uVar2 = FUN_00408020(g_rdmngr_msgq);
  uVar3 = rdmngr_get_msgq_len();
  printf("maxMsgNum:%d, maxMsgSize:%d, curMsgNum:%d",uVar1,uVar2,uVar3);
  return;
}

