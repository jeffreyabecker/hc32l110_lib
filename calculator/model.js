class CoreSystemClock{

}
function range(base, count, step){
    return new Array(count).fill(0).map((x,i)=>(i*(step || 1))+base)
}

function calculateBasicTimerFrequency(peripheralClockHz, targetFrequencyHz){
    const prescalerValues = [1,2,4,8,16,32,64,256];
    const tickSeconds = 1/peripheralClockHz;
    const targetPeriod = 1/targetFrequencyHz;
    let result = range(1,0xFFFD)
    .flatMap(r=>prescalerValues.map(p=>{
            return{ 
                prescaler:p,
                reload:r,
                target:targetPeriod,
                period: (targetPeriod * p) * r,
                difference: Math.abs((targetPeriod - ((targetPeriod * p) * r)) / targetPeriod)
            }
        }));
    return result.sort((a,b)=>a.difference - b.difference).slice(0,10)
}