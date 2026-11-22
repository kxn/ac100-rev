// func uac_md5_timer_destroy @ 0051d740 size=1

/* WARNING: Removing unreachable block (ram,0x0051cbc0) */

void uac_md5_timer_destroy(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_t9;
  int iVar6;
  
  (**(code **)(in_t9 + 0x23bfe0))(*(undefined4 *)(*(int *)(in_t9 + 0x23bc6c) + 0x3b1c),3);
  iVar6 = *(int *)(in_t9 + 0x23bcb8);
  iVar4 = *(int *)(iVar6 + 0x2393ac);
  if (*(int *)(iVar4 + 0x3b00) != 0) {
    uac_id_destroy();
  }
  iVar2 = *(int *)(iVar6 + 0x2391ac);
  iVar1 = 0;
  iVar5 = *(int *)(iVar6 + 0x2393ac);
  while (iVar3 = *(int *)(iVar6 + 0x2391ac), iVar1 < (1 << (*(uint *)(iVar2 + 0x2044) & 0x1f)) + -1)
  {
    iVar3 = *(int *)(iVar5 + 0x3ae4) + iVar1 * 0x6c;
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
  uac_mem_free_my(*(undefined4 *)(iVar5 + 0x3ae4));
  while (iVar2 = 0, iVar1 < *(int *)(iVar4 + 0x3aec)) {
    iVar2 = *(int *)(*(int *)(iVar4 + 0x3ae8) + iVar1 * 4);
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
  for (iVar1 = 0; iVar1 < *(int *)(iVar4 + 0x3af0); iVar1 = iVar1 + 1) {
    uac_mem_free_my(*(undefined4 *)(*(int *)(iVar4 + 0x3ae8) + iVar2 * 4));
    iVar2 = iVar2 + ((iVar2 + (1 << (*(uint *)(iVar3 + 0x2044) & 0x1f)) + -1) * 0x32) / 100;
  }
  uac_mem_free_my(*(undefined4 *)(iVar4 + 0x3ae8));
  uac_mutex_destroy(*(undefined4 *)(*(int *)(iVar6 + 0x2393ac) + 0x22d4));
  uac_mutex_destroy(*(undefined4 *)(iVar4 + 0x22d8));
  uac_cond_destroy(*(undefined4 *)(iVar4 + 0x22dc));
  return;
}

