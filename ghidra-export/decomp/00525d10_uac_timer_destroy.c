// func uac_timer_destroy @ 00525d10 size=1

/* WARNING: Removing unreachable block (ram,0x0052514c) */

void uac_timer_destroy(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_t9;
  int iVar6;
  
  (**(code **)(in_t9 + 0x233a10))(*(undefined4 *)(*(int *)(in_t9 + 0x233758) + 0x541c),3);
  (**(code **)(in_t9 + 0x233a10))(*(undefined4 *)(*(int *)(in_t9 + 0x233758) + 0x5420),3);
  iVar6 = *(int *)(in_t9 + 0x2336e8);
  iVar4 = *(int *)(iVar6 + 0x239468);
  if (*(int *)(iVar4 + 0x5400) != 0) {
    uac_id_destroy();
  }
  iVar2 = *(int *)(iVar6 + 0x2391ac);
  iVar1 = 0;
  iVar5 = *(int *)(iVar6 + 0x239468);
  while (iVar3 = *(int *)(iVar6 + 0x2391ac), iVar1 < (1 << (*(uint *)(iVar2 + 0x2064) & 0x1f)) + -1)
  {
    iVar3 = *(int *)(iVar5 + 0x53e4) + iVar1 * 0x6c;
    if ((*(byte *)(iVar3 + 0x54) & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    else if (*(code **)(iVar3 + 100) == (code *)0x0) {
      iVar1 = iVar1 + 1;
    }
    else {
      (**(code **)(iVar3 + 100))(*(undefined4 *)(iVar3 + 0x68));
      iVar1 = iVar1 + 1;
    }
  }
  iVar1 = 0;
  uac_mem_free_my(*(undefined4 *)(iVar5 + 0x53e4));
  while (iVar2 = 0, iVar1 < *(int *)(iVar4 + 0x53ec)) {
    iVar2 = *(int *)(*(int *)(iVar4 + 0x53e8) + iVar1 * 4);
    if ((*(byte *)(iVar2 + 0x54) & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    else if (*(code **)(iVar2 + 100) == (code *)0x0) {
      iVar1 = iVar1 + 1;
    }
    else {
      (**(code **)(iVar2 + 100))(*(undefined4 *)(iVar2 + 0x68));
      iVar1 = iVar1 + 1;
    }
  }
  for (iVar1 = 0; iVar1 < *(int *)(iVar4 + 0x53f0); iVar1 = iVar1 + 1) {
    uac_mem_free_my(*(undefined4 *)(*(int *)(iVar4 + 0x53e8) + iVar2 * 4));
    iVar2 = iVar2 + ((iVar2 + (1 << (*(uint *)(iVar3 + 0x2064) & 0x1f)) + -1) * 0x32) / 100;
  }
  uac_mem_free_my(*(undefined4 *)(iVar4 + 0x53e8));
  uac_mutex_destroy(*(undefined4 *)(*(int *)(iVar6 + 0x239468) + 0x3bd4));
  uac_mutex_destroy(*(undefined4 *)(iVar4 + 0x3bd8));
  uac_cond_destroy(*(undefined4 *)(iVar4 + 0x3bdc));
  return;
}

