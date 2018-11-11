#include "TimerManager.h"
#include "Animation/AnimInstance.h"

void Classname::Functionname()
{
	// try and fire a projectile
	if (bCanfire)//判定是否进行
	{
		bCanfire = false;//更改延迟条件
		
		????//添加延时内任意功能

		GetWorld()->GetTimerManager().SetTimer(FireDelayTimerHandle, this, &Afirstperson_codeCharacter::ResetFire, 3.0f, false);//计时3.0f(3s)并运行重置函数
	}
}
void Classname::ResetFire()
{
	bCanfire = true;//更改延迟条件
	GetWorldTimerManager().ClearTimer(FireDelayTimerHandle);//重置计时器
}
