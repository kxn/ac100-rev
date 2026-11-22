// func _radius_server_check @ 00444f08 size=1

undefined4 _radius_server_check(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int in_t9;
  code *pcVar7;
  undefined1 auStack_74 [20];
  int iStack_60;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iStack_60 = in_t9 + 0x31c1f8;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  iVar4 = *param_2;
  uVar5 = (uint)*(ushort *)(iVar4 + 2);
  iVar1 = (**(code **)(in_t9 + 0x314714))();
  if (uVar5 - 0x14 < 0x7ed) {
    uVar6 = uVar5 + iVar1;
    if ((int)uVar6 < 0x801) {
      (**(code **)(iStack_60 + -0x7910))(auStack_58,iVar4 + 4,0x10);
      iVar3 = 0;
      (**(code **)(iStack_60 + -0x7958))(iVar4 + 4,0,0x10);
      (**(code **)(iStack_60 + -0x7910))(iVar4 + uVar5,param_1,iVar1);
      _ac_md5_calc(auStack_48,iVar4,uVar6);
      iVar1 = (**(code **)(iStack_60 + -0x7a78))(auStack_58,auStack_48,0x10);
      if ((iVar1 != 0) && (iVar3 = -1, **(int **)(iStack_60 + -0x7fcc) != 0)) {
        (**(code **)(iStack_60 + -0x7830))
                  (*(int *)(iStack_60 + -0x7fe0) + 0x20c0,*(int *)(iStack_60 + -0x7fe0) + 0x2d30,
                   0x1044);
      }
      (**(code **)(iStack_60 + -0x7910))(iVar4 + 4,auStack_58,0x10);
      iVar1 = iStack_60;
      if (iVar3 != 0) {
        return 0;
      }
      for (uVar5 = 0; uVar5 < 0x14; uVar5 = uVar5 + 1) {
        auStack_74[uVar5] = *(undefined1 *)((int)param_2 + uVar5 + 0x138);
      }
      iVar1 = (**(code **)(iVar1 + -0x7f88))
                        (*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124),
                         *(undefined4 *)(param_1 + 0x128),*(undefined4 *)(param_1 + 300),
                         *(undefined4 *)(param_1 + 0x130));
      if (iVar1 == 0) {
        return 0;
      }
      (**(code **)(iStack_60 + -0x7f8c))(param_1 + 0xde,&uStack_38);
      if ((*(char *)(param_2 + 0x53) != '\0') &&
         (iVar4 = (**(code **)(iStack_60 + -0x7f44))
                            (param_2[0x53],param_2[0x54],param_2[0x55],param_2[0x56],param_2[0x57]),
         iVar1 = iStack_60, iVar4 != 0)) {
        for (uVar5 = 0; uVar5 < 0x14; uVar5 = uVar5 + 1) {
          auStack_74[uVar5] = *(undefined1 *)((int)&uStack_38 + uVar5);
        }
        iVar1 = (**(code **)(iVar1 + -0x7f88))
                          (param_2[0x53],param_2[0x54],param_2[0x55],param_2[0x56],param_2[0x57]);
        if (iVar1 == 0) {
          pcVar7 = *(code **)(iStack_60 + -0x7910);
          param_2[0x59] = 0x193;
          (*pcVar7)(param_2 + 1,param_1,0x134);
          return 0;
        }
      }
      (**(code **)(iStack_60 + -0x7910))(param_2 + 1,param_1,0x134);
      param_2[0x58] = 1;
      return 0;
    }
    if (**(int **)(iStack_60 + -0x7fcc) == 0) {
      return 0;
    }
    uVar2 = 0x1035;
    iVar4 = *(int *)(iStack_60 + -0x7fe0);
    iVar1 = *(int *)(iStack_60 + -0x7fe0) + 0x208c;
  }
  else {
    if (**(int **)(iStack_60 + -0x7fcc) == 0) {
      return 0;
    }
    uVar2 = 0x102e;
    iVar4 = *(int *)(iStack_60 + -0x7fe0);
    iVar1 = *(int *)(iStack_60 + -0x7fe0) + 0x2060;
    uVar6 = uVar5;
  }
  (**(code **)(iStack_60 + -0x7830))(iVar1,iVar4 + 0x2d30,uVar2,uVar6);
  return 0;
}

