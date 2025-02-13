#ifndef FastMapLite_h
#define FastMapLite_h

class FastMapLite
{
public:
 FastMapLite();
  bool init(float in_min, float in_max, float out_min, float out_max);
 float inline map(const float value) { float result= _base + value * _factor; return (value > _in_max) ?_out_max : ((value < _in_min) ? _out_min : result);}

private:
  float _in_min, _in_max, _out_min, _out_max;
  float _factor, _base;
};

FastMap::FastMapLite()
{
  init(0, 1, 0, 1);
}

bool FastMapLite::init(float in_min, float in_max, float out_min, float out_max)
{
  float _inRange = in_max - in_min;
  float _outRange = out_max - out_min;
 
  if ((_inRange == 0.0 ) || (_outRange == 0.0)) return false;

  _in_min = in_min;
  _in_max = in_max;
  _out_min = out_min;
  _out_max = out_max;

  _factor = _outRange/_inRange;
  _base = _out_min - _in_min * _factor;

  return true;
}
#endif

