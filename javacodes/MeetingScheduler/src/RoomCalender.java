import java.util.ArrayList;
import java.util.List;

public class RoomCalender {
    List<Meeting> meetingList;
    public RoomCalender(){
        meetingList = new ArrayList<>();
    }
    public boolean checkAvailability(int start, int end) {
        for (Meeting meeting : meetingList) {
            if (meeting.end > start && meeting.start < end)
                return false;
        }
        return true;
    }

    public Meeting scheduleMeeting(int start, int end, List<Attendee> attendeeList,Room room) {
        Meeting meeting = new Meeting(start,end,attendeeList,room);

        for (Attendee attendee : attendeeList){
            attendee.scheduleMeeting(meeting);
            attendee.notifyAttendee(meeting);
        }

        meetingList.add(meeting);

        return meeting;
    }
}
