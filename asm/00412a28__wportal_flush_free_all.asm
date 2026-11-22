; func _wportal_flush_free_all @ 0x00412a28 size=0x20
  412a28:	27bdffe0 	addiu	sp,sp,-32
  412a2c:	afbf001c 	sw	ra,28(sp)
  412a30:	0c104a20 	jal	0x412880
  412a34:	00002021 	move	a0,zero
  412a38:	24040001 	li	a0,1
  412a3c:	8fbf001c 	lw	ra,28(sp)
  412a40:	08104a20 	j	0x412880
  412a44:	27bd0020 	addiu	sp,sp,32
