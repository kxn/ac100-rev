// func __work_thread @ 0051c558 size=580

void __work_thread(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  code *pcVar10;
  int in_t9;
  undefined8 uVar11;
  undefined8 uVar12;
  
  iVar7 = *(int *)(in_t9 + 0x23ce54);
  do {
    uac_mutex_take(*(undefined4 *)(iVar7 + 0x22d8),0xffffffff);
    while (iVar3 = uac_list_first(*(int *)(in_t9 + 0x23ce54) + 0x3af4), iVar3 == 0) {
      uac_cond_wait(*(undefined4 *)(iVar7 + 0x22dc),*(undefined4 *)(iVar7 + 0x22d8),0xffffffff);
    }
    uac_list_remove(iVar3);
    uac_mutex_give(*(undefined4 *)(iVar7 + 0x22d8));
    bVar1 = *(byte *)(iVar3 + 0x54);
    pcVar9 = *(code **)(iVar3 + 0x60);
    pcVar10 = *(code **)(iVar3 + 100);
    uVar8 = *(undefined4 *)(iVar3 + 0x68);
    uVar11 = uac_time_secs();
    if (((bVar1 & 8) == 0) && (pcVar9 != (code *)0x0)) {
      (*pcVar9)(uVar8);
    }
    uVar12 = uac_time_secs();
    uVar5 = (uint)uVar12;
    uVar6 = uVar5 - (int)uVar11;
    if ((int)((ulonglong)uVar12 >> 0x20) - (int)((ulonglong)uVar11 >> 0x20) == (uint)(uVar5 < uVar6)
       ) {
      if (**(byte **)(in_t9 + 0x23ced8) < uVar6) {
        uVar4 = *(undefined4 *)(iVar3 + 0x50);
        goto LAB_0051c768;
      }
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x50);
LAB_0051c768:
      (**(code **)(in_t9 + 0x23d378))
                (*(int *)(in_t9 + 0x23cbd0) + 0x2744,*(int *)(in_t9 + 0x23cbd0) + 0x2db8,0x2b4,
                 iVar3 + 0x10,uVar4,uVar5 - (int)uVar11);
    }
    uac_mutex_take(*(undefined4 *)(iVar7 + 0x22d4),0xffffffff);
    bVar1 = *(byte *)(iVar3 + 0x54);
    if (((bVar1 & 8) == 0) && (((bVar1 & 2) != 0 || ((bVar1 & 0x10) != 0)))) {
      *(undefined1 *)(iVar3 + 0x54) = 1;
      if ((bVar1 & 2) != 0) {
        *(undefined1 *)(iVar3 + 0x54) = 3;
      }
      *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x58) + *(int *)(iVar7 + 0x22e0);
      bVar2 = false;
      internal_add_timer(iVar3);
    }
    else {
      uac_id_free(*(undefined4 *)(iVar7 + 0x3b00),*(uint *)(iVar3 + 0xc) & 0xfffff);
      *(undefined1 *)(iVar3 + 0x54) = 0;
      bVar2 = true;
    }
    uac_mutex_give(*(undefined4 *)(iVar7 + 0x22d4));
    if ((bVar2) && (pcVar10 != (code *)0x0)) {
      (*pcVar10)(uVar8);
    }
  } while( true );
}

