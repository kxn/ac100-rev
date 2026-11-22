// func cw_msg_ele_wtp_board_data_test @ 005d15fc size=1

void cw_msg_ele_wtp_board_data_test(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [40];
  undefined1 auStack_68 [4];
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [48];
  
  memcpy(auStack_40,&UNK_006f25e0,0x2e);
  memset(auStack_68,0,0x28);
  memset(auStack_90,0,0x28);
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  memcpy((void *)0x0,auStack_3c,0x2a);
  uStack_64 = 0x2a;
  uStack_62 = 0;
  uStack_9c = 0x26002a;
  iVar1 = (*(code *)PTR_cw_wtp_board_data_parse_0074cd7c)(auStack_68,&uStack_a8);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_cw_wtp_board_data_create_0074cd84)(uStack_98);
    if (iVar1 == 0) {
      uVar3 = 0x5ac;
      pcVar4 = "NULL != clone_msg_ele";
      goto code_r0x005d1744;
    }
    iVar2 = (*(code *)PTR_cw_wtp_board_data_dump_0074cd8c)(&uStack_a8);
    if (iVar2 == 0) {
      puts("************clone start************");
      iVar2 = (*(code *)PTR_cw_wtp_board_data_dump_0074cd8c)(iVar1);
      if (iVar2 == 0) {
        puts("*************clone end************");
        iVar2 = (*(code *)PTR_cw_wtp_board_data_free_0074cd88)(&uStack_a8);
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_cw_wtp_board_data_free_0074cd88)(iVar1);
          if (iVar2 == 0) {
            FUN_00407df0(iVar1);
            return;
          }
          uVar3 = 0x5ba;
        }
        else {
          uVar3 = 0x5b8;
        }
      }
      else {
        uVar3 = 0x5b3;
      }
    }
    else {
      uVar3 = 0x5af;
    }
  }
  else {
    uVar3 = 0x5a9;
  }
  pcVar4 = "ret == UAC_OK";
code_r0x005d1744:
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_msg_ele_wtp_board_data_test",uVar3,pcVar4);
  return;
}

