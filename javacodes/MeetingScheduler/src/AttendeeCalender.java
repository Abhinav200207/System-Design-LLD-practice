import java.util.ArrayList;
import java.util.List;

public class AttendeeCalender {
    List<Meeting> meetingList;
    public AttendeeCalender(){
        meetingList = new ArrayList<>();
    }
    public boolean isAvailable(int start, int end) {
        for (Meeting meeting : meetingList) {
//            System.out.println(meeting.start + " " + meeting.end);
            if (meeting.end > start && meeting.start < end)
                return false;
        }
        return true;
    }

    public void scheduleMeeting(Meeting meeting, String name) {
        meetingList.add(meeting);
        System.out.println(name +" "+meetingList.size());
    }
}
