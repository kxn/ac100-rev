// func __tick_thread @ 00524d70 size=620

undefined4 __tick_thread(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_t9;
  int iVar7;
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_34 = 0;
  local_30 = 500000;
  local_3c = 0;
  local_38 = 500000;
  iVar1 = (**(code **)(in_t9 + 0x234940))(0,&local_3c,0);
  if (-1 < iVar1) {
    iVar1 = *(int *)(in_t9 + 0x2346f8);
    iVar5 = *(int *)(in_t9 + 0x2346f8);
    iVar6 = *(int *)(in_t9 + 0x2346f8);
    iVar7 = *(int *)(in_t9 + 0x2346f8);
    do {
      do {
        iVar2 = (**(code **)(in_t9 + 0x2348a8))(iVar5 + 0x5404,auStack_40);
      } while (iVar2 != 0);
      uVar3 = *(uint *)(iVar1 + 0x3be0);
      uac_mutex_take(*(undefined4 *)(iVar1 + 0x3bd4),0xffffffff);
      if ((uVar3 & 0xff) == 0) {
        iVar2 = cascade(iVar7 + 0x47e4,(uVar3 << 0x12) >> 0x1a);
        if (iVar2 == 0) {
          iVar2 = cascade(*(int *)(in_t9 + 0x2346f8) + 0x4ae4,(uVar3 << 0xc) >> 0x1a);
          if (iVar2 == 0) {
            iVar2 = cascade(*(int *)(in_t9 + 0x2346f8) + 0x4de4,(uVar3 << 6) >> 0x1a);
            if (iVar2 == 0) {
              cascade(*(int *)(in_t9 + 0x2346f8) + 0x50e4,uVar3 >> 0x1a);
            }
          }
        }
      }
      *(int *)(iVar1 + 0x3be0) = *(int *)(iVar1 + 0x3be0) + 1;
      iVar4 = iVar1 + (uVar3 & 0xff) * 0xc + 0x3be4;
      iVar2 = uac_list_size(iVar4);
      if (iVar2 != 0) {
        uac_mutex_take(*(undefined4 *)(iVar1 + 0x3bd8),0xffffffff);
        while (iVar2 = uac_list_first(iVar4), iVar2 != 0) {
          *(byte *)(iVar2 + 0x54) = *(byte *)(iVar2 + 0x54) | 4;
          uac_list_remove(iVar2);
          uac_list_insert_last(iVar6 + 0x53f4,iVar2);
        }
        uac_cond_signal(*(pthread_cond_t **)(iVar1 + 0x3bdc));
        uac_mutex_give(*(undefined4 *)(iVar1 + 0x3bd8));
      }
      uac_mutex_give(*(undefined4 *)(iVar1 + 0x3bd4));
      notify_excute_md5_tick_proc();
    } while( true );
  }
  (**(code **)(in_t9 + 0x234b60))
            (*(int *)(in_t9 + 0x2343b8) + 0x3f28,*(int *)(in_t9 + 0x2343b8) + 0x3f44,0x176);
  return 0;
}

