; func add_rslt_code_to_parsed_pkt @ 0x00598960 size=0x38
  598960:	27bdffd8 	addiu	sp,sp,-40
  598964:	24050021 	li	a1,33
  598968:	27a60018 	addiu	a2,sp,24
  59896c:	00003821 	move	a3,zero
  598970:	afbf0024 	sw	ra,36(sp)
  598974:	0c1621be 	jal	0x5886f8
  598978:	afa00018 	sw	zero,24(sp)
  59897c:	2403ffff 	li	v1,-1
  598980:	00021027 	nor	v0,zero,v0
  598984:	8fbf0024 	lw	ra,36(sp)
  598988:	0002180b 	movn	v1,zero,v0
  59898c:	27bd0028 	addiu	sp,sp,40
  598990:	03e00008 	jr	ra
  598994:	00601021 	move	v0,v1
