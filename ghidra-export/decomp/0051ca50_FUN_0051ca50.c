// func FUN_0051ca50 @ 0051ca50 size=504

/* WARNING: Removing unreachable block (ram,0x0051cbc0) */

void FUN_0051ca50(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_00783b00 != 0) {
    uac_id_destroy();
  }
  puVar1 = PTR_DAT_007591ac;
  iVar4 = 0;
  while (puVar2 = PTR_DAT_007591ac, iVar4 < (1 << (*(uint *)(puVar1 + 0x2044) & 0x1f)) + -1) {
    iVar3 = DAT_00783ae4 + iVar4 * 0x6c;
    if ((*(byte *)(iVar3 + 0x54) & 1) == 0) {
      iVar4 = iVar4 + 1;
    }
    else if (*(code **)(iVar3 + 100) == (code *)0x0) {
      iVar4 = iVar4 + 1;
    }
    else {
      (**(code **)(iVar3 + 100))(*(undefined4 *)(iVar3 + 0x68));
      iVar4 = iVar4 + 1;
    }
  }
  iVar4 = 0;
  uac_mem_free_my(DAT_00783ae4);
  while (iVar3 = 0, iVar4 < DAT_00783aec) {
    iVar3 = *(int *)(DAT_00783ae8 + iVar4 * 4);
    if ((*(byte *)(iVar3 + 0x54) & 1) == 0) {
      iVar4 = iVar4 + 1;
    }
    else if (*(code **)(iVar3 + 100) == (code *)0x0) {
      iVar4 = iVar4 + 1;
    }
    else {
      (**(code **)(iVar3 + 100))(*(undefined4 *)(iVar3 + 0x68));
      iVar4 = iVar4 + 1;
    }
  }
  for (iVar4 = 0; iVar4 < DAT_00783af0; iVar4 = iVar4 + 1) {
    uac_mem_free_my(*(undefined4 *)(DAT_00783ae8 + iVar3 * 4));
    iVar3 = iVar3 + ((iVar3 + (1 << (*(uint *)(puVar2 + 0x2044) & 0x1f)) + -1) * 0x32) / 100;
  }
  uac_mem_free_my(DAT_00783ae8);
  uac_mutex_destroy(g_wheel_md5_timer_base);
  uac_mutex_destroy(DAT_007822d8);
  uac_cond_destroy(DAT_007822dc);
  return;
}

