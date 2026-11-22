// func _uac_cfg_chk_task @ 00512c38 size=1

void _uac_cfg_chk_task(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_t9;
  code *pcVar8;
  
  iVar5 = *(int *)(in_t9 + 0x2464f0);
  iVar6 = *(int *)(in_t9 + 0x2464f0);
  iVar7 = *(int *)(in_t9 + 0x2464f0);
  iVar4 = *(int *)(in_t9 + 0x246774);
  iVar3 = *(int *)(in_t9 + 0x246774);
code_r0x00512c88:
  do {
    pcVar8 = *(code **)(in_t9 + 0x2469f4);
    do {
      (*pcVar8)(1);
      if (*(int *)(iVar4 + 0x1a70) == 0) goto code_r0x00512c88;
      iVar2 = *(int *)(*(int *)(in_t9 + 0x246574) + 0x1dc4);
      iVar1 = *(int *)(iVar3 + 0x1a88) + 1;
      *(int *)(iVar3 + 0x1a88) = iVar1;
      if (iVar2 == 0) {
        trap(7);
      }
      pcVar8 = *(code **)(in_t9 + 0x2469f4);
    } while (iVar1 % iVar2 != 0);
    iVar2 = *(int *)(in_t9 + 0x246774);
    iVar1 = *(int *)(in_t9 + 0x246774);
    if (*(int *)(iVar2 + 0x1a74) != 0) {
      if (*(int *)(*(int *)(in_t9 + 0x246774) + 0x1a6c) != 1) {
        if (**(int **)(in_t9 + 0x24676c) != 0) {
          (**(code **)(in_t9 + 0x246c98))(iVar6 + 0x794,iVar7 + 0xc28,0x127);
        }
        (**(code **)(in_t9 + 0x246b04))(iVar5 + 0x7c0);
        *(undefined4 *)(iVar2 + 0x1a74) = 0;
      }
      iVar1 = *(int *)(in_t9 + 0x246774);
    }
    *(undefined4 *)(iVar1 + 0x1a88) = 0;
  } while( true );
}

