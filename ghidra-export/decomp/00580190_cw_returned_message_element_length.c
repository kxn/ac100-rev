// func cw_returned_message_element_length @ 00580190 size=24

int cw_returned_message_element_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 1) + 2;
  }
  return iVar1;
}

