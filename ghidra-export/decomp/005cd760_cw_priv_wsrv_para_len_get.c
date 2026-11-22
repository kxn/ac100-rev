// func cw_priv_wsrv_para_len_get @ 005cd760 size=168

short cw_priv_wsrv_para_len_get(int param_1)

{
  short sVar1;
  
  if (param_1 != 0) {
    switch(*(undefined1 *)(param_1 + 8)) {
    case 0:
      return 9;
    case 1:
    case 4:
      return *(short *)(*(int *)(param_1 + 9) + 6) + 0x11;
    case 2:
      sVar1 = *(short *)(*(int *)(param_1 + 9) + 0x19);
      if (*(char *)(*(int *)(param_1 + 9) + 6) != '\0') {
        return sVar1 + 0x23;
      }
      return sVar1 + 0x17;
    case 3:
      return 0x8f;
    }
  }
  return 0;
}

