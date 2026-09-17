select
  a.measured_at as today,
  b.measured_at as next_day,
  a.pm10,
  b.pm10 as next_pm10
from measurements as a
join measurements as b
    on date_add(a.measured_at, interval 1 day) = b.measured_at
where a.pm10 < b.pm10;