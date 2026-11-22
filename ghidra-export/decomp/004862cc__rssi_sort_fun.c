// func _rssi_sort_fun @ 004862cc size=412

int _rssi_sort_fun(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = _nbr_filter((int)*(char *)(param_3 + 1),param_3[3],*param_3,param_3[4],
                      param_3[5] + param_1 * 0x18);
  iVar2 = _nbr_filter((int)*(char *)(param_3 + 1),param_3[3],*param_3,param_3[4],
                      param_3[5] + param_2 * 0x18);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      iVar5 = param_3[5] + param_1 * 0x18;
      iVar4 = param_3[5] + param_2 * 0x18;
      iVar2 = *(int *)(iVar5 + 0x14);
      iVar1 = *(int *)(iVar4 + 0x14);
      if (iVar2 == -1) {
        iVar2 = (int)*(char *)(iVar5 + 0xc);
        iVar4 = (int)*(char *)(iVar4 + 0xc);
        if (iVar1 == -1) {
          iVar3 = 0;
          if ((iVar2 != iVar4) && (iVar3 = 1, iVar4 <= iVar2)) {
            iVar3 = iVar1;
          }
        }
        else {
          iVar3 = -1;
          if ((iVar2 < iVar4) && ((int)(uint)*(byte *)(*param_3 + 0x1d) < iVar4 - iVar2)) {
            iVar3 = 1;
          }
        }
      }
      else if (iVar1 == -1) {
        iVar3 = 1;
        if (((int)*(char *)(iVar4 + 0xc) < (int)*(char *)(iVar5 + 0xc)) &&
           ((int)(uint)*(byte *)(*param_3 + 0x1d) <
            (int)*(char *)(iVar5 + 0xc) - (int)*(char *)(iVar4 + 0xc))) {
          iVar3 = iVar1;
        }
      }
      else {
        iVar3 = 0;
        if ((iVar2 != iVar1) && (iVar3 = 1, iVar1 <= iVar2)) {
          iVar3 = -1;
        }
      }
    }
    else {
      *(undefined1 *)((int)param_3 + param_2 + 0x18) = 1;
      iVar3 = -1;
    }
  }
  else if (iVar2 == 0) {
    *(undefined1 *)((int)param_3 + param_1 + 0x18) = 1;
    iVar3 = 1;
  }
  else {
    *(undefined1 *)((int)param_3 + param_1 + 0x18) = 1;
    *(undefined1 *)((int)param_3 + param_2 + 0x18) = 1;
    iVar3 = 0;
  }
  return iVar3;
}

