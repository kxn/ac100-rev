// func uac_str_to_hex @ 005228c8 size=180

undefined4 uac_str_to_hex(undefined1 *param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  ulong uVar2;
  char *pcVar3;
  char local_20;
  char local_1f;
  undefined1 local_1e;
  
  uVar1 = 0;
  local_1e = 0;
  if ((param_1 != (undefined1 *)0x0) && (pcVar3 = param_2, param_2 != (char *)0x0)) {
    while( true ) {
      local_20 = *pcVar3;
      if (local_20 == '\0') break;
      if (param_3 <= (int)pcVar3 - (int)param_2) {
        return 1;
      }
      local_1f = pcVar3[1];
      uVar2 = strtoul(&local_20,(char **)0x0,0x10);
      *param_1 = (char)uVar2;
      param_1 = param_1 + 1;
      pcVar3 = pcVar3 + 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

