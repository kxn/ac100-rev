// func _apmngr_trim_single_quota @ 005432d0 size=96

void _apmngr_trim_single_quota(char *param_1,char *param_2,int param_3)

{
  while( true ) {
    if ((*param_2 == '\0') || (param_3 < 2)) break;
    *param_1 = *param_2;
    if ((*param_2 == '\'') && (param_3 + -1 != 1)) {
      param_1[1] = '\'';
      param_3 = param_3 + -2;
      param_1 = param_1 + 2;
      param_2 = param_2 + 1;
    }
    else {
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    }
  }
  *param_1 = '\0';
  return;
}

