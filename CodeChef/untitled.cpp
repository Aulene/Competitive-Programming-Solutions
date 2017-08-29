
		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=1; i<n; i++)
			{
				intervals[i-1].pointa=a[i-1];
				intervals[i-1].pointb=a[i];

				if(intervals[i-1].pointa > intervals[i-1].pointb)
					{
						f=intervals[i-1].pointa;
						intervals[i-1].pointa=intervals[i-1].pointb;
						intervals[i-1].pointb=f;
					}
			}